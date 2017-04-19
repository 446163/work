" NORMAL VIMRC FILE
" anime is silly
" gotcha

"let g:python_host_skip_check=0
"let g:loaded_python3_provider=0

call plug#begin()

Plug 'W0rp/ale'
Plug 'lervag/vimtex'
Plug 'fcpg/vim-orbital'
"Plug 'scrooloose/syntastic'
Plug 'jiangmiao/auto-pairs'
Plug 'bling/vim-bufferline'
Plug 'ajh17/VimCompletesMe'
Plug 'wesQ3/vim-windowswap'
Plug 'itchyny/lightline.vim'
Plug 'airblade/vim-gitgutter'
"Plug 'valloric/youcompleteme'
Plug 'prendradjaja/vim-vertigo'
Plug 'haya14busa/incsearch.vim'
Plug 'christoomey/vim-tmux-navigator' 
Plug 'https://github.com/xuhdev/vim-latex-live-preview.git'

call plug#end()

let @s = "[sz=1``"
let mapleader="\<Backspace>"
let g:windowswap_map_keys = 0

map <space> a
map <m-K> 5<C-W>-
map <m-J> 5<C-W>+
map <m-L> 5<C-W>>
map <m-H> 5<C-W><
nnoremap <F1> :b1<CR> 
nnoremap <F2> :b2<CR>
nnoremap <F3> :b3<CR>
nnoremap <F4> :b4<CR>
nnoremap <F5> :b5<CR>
nnoremap <F6> :b6<CR>
nnoremap <F7> :b7<CR>
nnoremap <F8> :b8<CR>
nnoremap <F9> :b8<CR>
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l
tnoremap <Esc> <C-\><C-n>
noremap <buffer> <silent> k gk
noremap <buffer> <silent> j gj
tnoremap <C-h> <C-\><C-n><C-w>h
tnoremap <C-j> <C-\><C-n><C-w>j
tnoremap <C-k> <C-\><C-n><C-w>k
tnoremap <C-l> <C-\><C-n><C-w>l

vmap <leader>y "+y
vmap <leader>d "+d
vmap <leader>p "+p
nmap <leader>p "+p  
noremap <leader>w :w<cr>
noremap <leader>q :wq<cr>
noremap <leader>Q :q!<cr>

noremap <leader>mx :silent exec "!mpc toggle &"<cr>
noremap <leader>mc :silent exec "!mpc next &"<cr>
noremap <leader>mz :silent exec "!mpc prev &"<cr>
noremap <leader>md :silent exec "!mpc toggle &"<cr>
noremap <leader>mf :silent exec "!mpc next &"<cr>
noremap <leader>ms :silent exec "!mpc prev &"<cr>

nnoremap <leader>cc :w!%.c<cr>:!c % <cr>
nnoremap <silent> <leader>sw :call WindowSwap#EasyWindowSwap()<CR>

set nu
set rnu
set exrc
set hidden
set cindent
set mouse=n
set wrap lbr
set t_Co=256
set showmatch
set incsearch
set tabstop=4
set nohlsearch
set autoindent
set noshowmode
set splitbelow
set splitright
set shiftwidth=4

nnoremap <silent> <leader>n :<C-U>VertigoDown n<CR>
vnoremap <silent> <leader>n :<C-U>VertigoDown v<CR>
onoremap <silent> <leader>n :<C-U>VertigoDown o<CR>
nnoremap <silent> <leader>e :<C-U>VertigoUp n<CR>
vnoremap <silent> <leader>e :<C-U>VertigoUp v<CR>
onoremap <silent> <leader>e :<C-U>VertigoUp o<CR>

let g:Vertigo_homerow = 'arstdhneio'
let g:Vertigo_homerow_onedigit = 'qwfpgjluy;'

map /  <Plug>(incsearch-forward)
map ?  <Plug>(incsearch-backward)
map g/ <Plug>(incsearch-stay)

set hlsearch
let g:incsearch#auto_nohlsearch = 1
map n  <Plug>(incsearch-nohl-n)
map N  <Plug>(incsearch-nohl-N)
map *  <Plug>(incsearch-nohl-*)
map #  <Plug>(incsearch-nohl-#)
map g* <Plug>(incsearch-nohl-g*)
map g# <Plug>(incsearch-nohl-g#)

command! -nargs=* -complete=shellcmd Rsplit execute "new | r! <args>"
"set bg=NONE
"autocmd VimEnter * colorscheme orbital

colorscheme orbital

"hi Normal guibg=NONE ctermbg=NONE

autocmd FileType text,markdown let b:vcm_tab_complete = 'dict'

augroup myvimrc
    au!
    au BufWritePost .vimrc,_vimrc,vimrc,.gvimrc,_gvimrc,gvimrc so $MYVIMRC | if has('gui_running') | so $MYGVIMRC | endif
augroup END

let g:lightline = {
\ 'colorscheme': 'orbital',
\ 'component': {
\ 'readonly': '%{&readonly?"Ξ":""}',
\ },
\ 'separator': { 'left': '▶', 'right': '◀' },
\ 'subseparator': { 'left': '»', 'right': '«' }
\ }

" Vertical Split Buffer Function
function VerticalSplitBuffer(buffer)
    execute "vert belowright sb" a:buffer 
endfunction

" Vertical Split Buffer Mapping
command -nargs=1 Vbuffer call VerticalSplitBuffer(<f-args>)

