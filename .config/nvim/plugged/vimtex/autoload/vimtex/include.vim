" vimtex - LaTeX plugin for Vim
"
" Maintainer: Karl Yngve Lervåg
" Email:      karl.yngve@gmail.com
"

function! vimtex#include#expr() " {{{1
  "
  " First try \include or \input
  "
  let l:file = s:include()
  for l:suffix in split(&l:suffixesadd, ',')
    let l:candidate = l:file . l:suffix
    if filereadable(l:candidate)
      return l:candidate
    endif
  endfor

  "
  " Next search for file with kpsewhich
  "
  for l:file in s:vfname_split()
    for l:suffix in  reverse(split(&l:suffixesadd, ',')) + ['']
      let l:candidate = vimtex#kpsewhich#find(l:file . l:suffix)
      if filereadable(l:candidate)
        return l:candidate
      endif
    endfor
  endfor

  return v:fname
endfunction

" }}}1

function! s:include() " {{{1
  let [l:lnum, l:cnum] = searchpairpos(&l:include, '', '}', 'bnW')
  if l:lnum != line('.') | return '' | endif

  let l:cmd = vimtex#cmd#get_at(l:lnum, l:cnum)
  let l:args = get(l:cmd, 'args', [{'text' : ''}])
  let l:file = l:args[0].text
  let l:file = substitute(l:file, '^\s*"\|"\s*$', '', 'g')
  let l:file = substitute(l:file, '\\space', '', 'g')

  return l:file
endfunction

" }}}1
function! s:vfname_split() " {{{1
  let l:files = []

  let l:current = expand('<cword>')
  if index(split(v:fname, ','), l:current) >= 0
    call add(l:files, l:current)
  endif

  return l:files + [v:fname]
endfunction

" }}}1

" vim: fdm=marker sw=2
