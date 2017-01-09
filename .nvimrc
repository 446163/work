" WORK VIMRC FILE

let g:python_host_skip_check=1
let g:loaded_python3_provider=1

call plug#begin()
Plug 'tpope/vim-sensible'
Plug 'scrooloose/syntastic'
Plug 'bling/vim-bufferline'
Plug 'wesQ3/vim-windowswap'
Plug 'itchyny/lightline.vim'
Plug 'valloric/youcompleteme'
Plug 'airblade/vim-gitgutter'
Plug 'https://github.com/suan/vim-instant-markdown.git'
Plug 'tpope/vim-fugitive'
call plug#end()

let @s = "[sz=1``"

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
tnoremap <C-h> <C-\><C-n><C-w>h
tnoremap <C-j> <C-\><C-n><C-w>j
tnoremap <C-k> <C-\><C-n><C-w>k
tnoremap <C-l> <C-\><C-n><C-w>l
nnoremap <CR> :vsp term://$SHELL<CR>i
nnoremap <A-CR> :sp term://$SHELL<CR>i

set nu
set exrc
set mouse=n
set wrap lbr
set t_Co=256
set showmatch
set splitbelow
set splitright
set noshowmode
set updatetime=100
set complete+=kspell
set spell spelllang=en_gb

let g:gitgutter_eager = 1
let g:gitgutter_realtime = 1
let g:instant_markdown_autostart = 1
let g:instant_markdown_open_to_the_world = 1

autocmd BufRead,BufNewFile *.md setlocal spell

let g:lightline = {
\ 'colorscheme': 'landscape',
\ 'component': {
\ 'readonly': '%{&readonly?"Ξ":""}',},
\ 'separator': { 'left': '▶', 'right': '◀' },
\ 'subseparator': { 'left': '»', 'right': '«' }
\ }

augroup scrollLed
	au!
	autocmd InsertEnter * silent exe "!xset led"
	autocmd Insertleave * silent exe "!xset -led"
augroup END

colorscheme torte
