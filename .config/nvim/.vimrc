call plug#begin()
Plug 'tpope/vim-sensible'
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
Plug 'junegunn/fzf.vim'
Plug 'vim-airline/vim-airline'
Plug 'scrooloose/syntastic'
Plug 'tpope/vim-surround'
Plug 'valloric/youcompleteme'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'bling/vim-bufferline'
Plug 'severin-lemaignan/vim-minimap' 
Plug 'altercation/vim-colors-solarized'

set t_Co=256

map <C-K> :bnext<CR>
map <C-J> :bprev<CR>
map <C-L> :bnext<CR>
map <C-H> :bprev<CR>
map <space> a
map <C-M> :MinimapToggle<CR>

autocmd VimEnter * AirlineTheme base16_colors  

set background=dark
set nu
set showmatch
set ruler
set complete+=kspell
set spell spelllang=en_gb

let g:airline_powerline_fonts = 1

Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
call plug#end()

set nu
