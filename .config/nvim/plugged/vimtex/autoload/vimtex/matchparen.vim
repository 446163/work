" vimtex - LaTeX plugin for Vim
"
" Maintainer: Karl Yngve Lervåg
" Email:      karl.yngve@gmail.com
"

function! vimtex#matchparen#init_buffer() " {{{1
  if !g:vimtex_matchparen_enabled | return | endif

  call vimtex#matchparen#enable()
endfunction

" }}}1

function! vimtex#matchparen#enable() " {{{1
  " vint: -ProhibitAutocmdWithNoGroup

  execute 'augroup vimtex_matchparen' . bufnr('%')
    autocmd!
    autocmd CursorMoved  <buffer> call s:matchparen.highlight()
    autocmd CursorMovedI <buffer> call s:matchparen.highlight()
  augroup END

  call s:matchparen.highlight()

  " vint: +ProhibitAutocmdWithNoGroup
endfunction

" }}}1
function! vimtex#matchparen#disable() " {{{1
  call s:matchparen.clear()
  execute 'autocmd! vimtex_matchparen' . bufnr('%')
endfunction

" }}}1

let s:matchparen = {}

function! s:matchparen.clear() abort dict " {{{1
  silent! call matchdelete(w:vimtex_match_id1)
  silent! call matchdelete(w:vimtex_match_id2)
  unlet! w:vimtex_match_id1
  unlet! w:vimtex_match_id2
endfunction
function! s:matchparen.highlight() abort dict " {{{1
  call self.clear()

  if vimtex#util#in_comment() | return | endif

  let l:current = vimtex#delim#get_current('all', 'both')
  if empty(l:current) | return | endif

  let l:corresponding = vimtex#delim#get_matching(l:current)
  if empty(l:corresponding) | return | endif

  let [l:open, l:close] = l:current.is_open
        \ ? [l:current, l:corresponding]
        \ : [l:corresponding, l:current]

  let w:vimtex_match_id1 = matchadd('MatchParen',
        \ '\%' . l:open.lnum . 'l\%' . l:open.cnum . 'c' . l:open.re.this)
  let w:vimtex_match_id2 = matchadd('MatchParen',
        \ '\%' . l:close.lnum . 'l\%' . l:close.cnum . 'c' . l:close.re.this)
endfunction

" }}}1

" vim: fdm=marker sw=2
