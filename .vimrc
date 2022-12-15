"General settings
let mapleader = " "
set number relativenumber
set scrolloff=5
syntax on
set colorcolumn=120
set cursorline
:nnoremap <Leader>c :set cursorcolumn!<CR>
:nnoremap <F9>:w <CR>
"Plugin call
call plug#begin()
	Plug 'dense-analysis/ale'
	
	Plug 'frazrepo/vim-rainbow'

	Plug 'preservim/nerdtree'
	
	Plug 'itchyny/lightline.vim'

	Plug 'garbas/vim-snipmate'

	Plug 'MarcWeber/vim-addon-mw-utils'

	Plug 'tomtom/tlib_vim'

	Plug 'lervag/vimtex'

	Plug 'neoclide/coc.nvim', {'branch': 'release'}

call plug#end()

"Remap of Multiwindow movement
nmap<silent> <C-j> <C-w>j
nmap<silent> <C-h> <C-w>h
nmap<silent> <C-k> <C-w>k
nmap<silent> <C-l> <C-w>l

source  ~/.vim/.config/Snip-Mate.vim

source  ~/.vim/.config/NERDTree.vim

source ~/.vim/.config/lightline.vim

source ~/.vim/.config/vimtex.vim

source ~/.vim/.config/coc.vim


