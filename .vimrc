"General settings
set number relativenumber
set scrolloff=5
syntax on

"Plugin call
call plug#begin()
	Plug 'dense-analysis/ale'
	
	Plug 'frazrepo/vim-rainbow'

	Plug 'preservim/nerdtree'
	
	Plug 'itchyny/lightline.vim'

	Plug 'garbas/vim-snipmate'

	Plug 'MarcWeber/vim-addon-mw-utils'

	Plug 'tomtom/tlib_vim'
call plug#end()


set laststatus=2

let mapleader = " "
nnoremap <leader>w :NERDTree<CR>
let NERDTreeShowHidden=1

"Snip-Mate
"let g:snipMate = { 'snippet_version' : 1 }

"Remap of Multiwindow movement
nmap<silent> <C-j> <C-w>j
nmap<silent> <C-h> <C-w>h
nmap<silent> <C-k> <C-w>k
nmap<silent> <C-l> <C-w>l



source  ~/.vim/.config/Snip-Mate.vim

