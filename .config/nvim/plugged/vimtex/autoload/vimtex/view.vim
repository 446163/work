" vimtex - LaTeX plugin for Vim
"
" Maintainer: Karl Yngve Lervåg
" Email:      karl.yngve@gmail.com
"

function! vimtex#view#init_buffer() " {{{1
  if !g:vimtex_view_enabled | return | endif

  command! -buffer -nargs=? -complete=file VimtexView
        \ call b:vimtex.viewer.view(<q-args>)
  if has_key(b:vimtex.viewer, 'reverse_search')
    command! -buffer -nargs=* VimtexRSearch
          \ call b:vimtex.viewer.reverse_search()
  endif

  nnoremap <buffer> <plug>(vimtex-view)
        \ :call b:vimtex.viewer.view('')<cr>
  if has_key(b:vimtex.viewer, 'reverse_search')
    nnoremap <buffer> <plug>(vimtex-reverse-search)
          \ :call b:vimtex.viewer.reverse_search()<cr>
  endif
endfunction

" }}}1
function! vimtex#view#init_state(state) " {{{1
  if !g:vimtex_view_enabled | return | endif
  if has_key(a:state, 'viewer') | return | endif

  try
    let a:state.viewer = vimtex#view#{g:vimtex_view_method}#new()
  catch /E117/
    call vimtex#echo#warning('viewer '
          \ . g:vimtex_view_method . ' does not exist!')
    call vimtex#echo#echo('- Please see :h g:vimtex_view_method')
    call vimtex#echo#wait()
    return
  endtry

  " Make the following code more concise
  let l:v = a:state.viewer

  "
  " Add compiler callback to callback hooks (if it exists)
  "
  if exists('*l:v.compiler_callback')
    call add(g:vimtex_compiler_callback_hooks,
          \ 'b:vimtex.viewer.compiler_callback')
  endif

  "
  " Create view and/or callback hooks (if they exist)
  "
  for l:point in ['view', 'callback']
    execute 'let l:hook = ''g:vimtex_view_'
          \ . g:vimtex_view_method . '_hook_' . l:point . ''''
    if exists(l:hook)
      execute 'let hookfunc = ''*'' . ' . l:hook
      if exists(hookfunc)
        execute 'let l:v.hook_' . l:point . ' = function(' . l:hook . ')'
      endif
    endif
  endfor
endfunction

" }}}1

" vim: fdm=marker sw=2
