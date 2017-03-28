" WORK VIMRC FILE 
let g:python_host_skip_check=1
let g:loaded_python3_provider=1

call plug#begin()

Plug 'tpope/vim-fugitive'
Plug 'scrooloose/syntastic'
Plug 'bling/vim-bufferline'
Plug 'wesQ3/vim-windowswap'
Plug 'itchyny/lightline.vim'
"Plug 'airblade/vim-gitgutter'
"Plug 'valloric/youcompleteme'

Plug 'https://github.com/suan/vim-instant-markdown.git'
Plug 'lervag/vimtex' 


"Plug 'mattn/emmet-vim'
call plug#end()

let @s="[sz=!1``"
let mapleader="\<Backspace>"
let maplocalleader="\<Backspace>"
let g:vimtex_view_general_viewer = 'okular' 

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

vmap <leader>y "+y<ESC> 
vmap <leader>d "+d<ESC> 
vmap <leader>p "+p<ESC> 
vmap <leader>p "+p<ESC> 
nmap <leader>p "+p<ESC> 
nmap <leader>p "+p<ESC>   
imap @@ <Esc>@sa
nnoremap <leader>w :w<cr>
nnoremap <leader>q :wq<cr>
nnoremap <leader>Q :q!<cr>
nnoremap <leader>g1 :Gw<CR>
nnoremap <leader>g2 :Gcommit<CR>
nnoremap <leader>g3 :Gpush<CR>
nnoremap <leader>gw :Gw<CR>
nnoremap <leader>gc :Gcommit<CR>
nnoremap <leader>gp :Gpush<CR>

set nu
set exrc
set mouse=n
set showcmd
set wrap lbr
set t_Co=256
set showmatch
set splitbelow
set splitright
set noshowmode
set updatetime=10
set complete+=kspell
set spell spelllang=en_gb
"let g:user_emmet_install_global = 0
"autocmd FileType html,css EmmetInstall
"let g:user_emmet_leader_key='<C-w>'

let g:instant_markdown_autostart = 1
let g:instant_markdown_open_to_the_world = 1

autocmd VimEnter * colorscheme orbital

autocmd BufRead,BufNewFile *.md setlocal spell

let g:lightline = {
\ 'colorscheme': 'orbital',
\ 'component': {
\ 'readonly': '%{&readonly?"Ξ":""}',},
\ 'separator': { 'left': '▶', 'right': '◀' },
\ 'subseparator': { 'left': '»', 'right': '«' }
\ }

let g:lightline.colorscheme = 'orbital'
