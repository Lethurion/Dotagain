set updatetime=300
set signcolumn=yes
highlight CocFloating ctermbg=White  ctermfg=Black
inoremap <silent><expr> <Tab>
      \ coc#pum#visible() ? coc#pum#next(1) :
            \ CheckBackspace() ? "\<Tab>" :
	          \ coc#refresh()
inoremap <expr><Alt-TAB> coc#pum#visible() ? coc#pum#prev(1) : "\<C-h>"
function! CheckBackspace() abort
	  let col = col('.') - 1
	    return !col || getline('.')[col - 1]  =~# '\s'
endfunction
