 set wildmenu
 set wildmode=list:longest

" enable the syntax color
:syntax on

"monokai color scheme
syntax enable
colorscheme molokai
let g:molokai_original = 1
let g:rehash256 = 1
set title
set number
set ruler
set showcmd
set mouse=a
set ignorecase
set showmatch
set autoindent

" allow copy/paste through vim windows
set clipboard=unnamed

" background
set background=dark

" tabulations configuration
set shiftwidth=4
set softtabstop=4
set tabstop=4

" set a maximum of 80rows
set textwidth=80

" highlight all function names
syntax match cCustomFunc /\w\+\s*(/me=e-1,he=e-1
highlight def link cCustomFunc Function

" highlight trailing whitespace
highlight Error ctermbg=red
match Error /\s\+$\| \+\ze\t/
match Error /^\t*\zs \+/
match Error /\s\+$/
let g:airline_theme='badwolf'
set laststatus=2

" autopair configuration
"" C
inoremap ( ()<left>
inoremap { {}<left>
inoremap < <><left>
inoremap [ []<left>
inoremap ;	<End>;
"" HTML
inoremap <ht <html><CR><CR></html><Up><Tab>
inoremap <he <head><CR><CR></head><Up><Tab><Tab>
inoremap <bo <body><CR><CR></body><Up><Tab><Tab>
inoremap <ti <title></title><left><left><left><left><left><left><left><left>
inoremap <im <img id="" src=""><left><left>
inoremap <h1 <h1></h1><left><left><left><left><left>
inoremap <h2 <h2></h2><left><left><left><left><left>
inoremap <h3 <h3></h4><left><left><left><left><left>
inoremap <di <div id="" class=""><CR><CR></div><Up><Tab><Tab><Tab>

inoremap <p <p></p><left><left><left><left>
inoremap <hr <a href=""></a><left><left><left><left><left><left>
"" PHP
inoremap <? <?php<CR><CR>?><Up><Tab>


" auto condition configuration
""inoremap while while <CR>{<CR>}<left><CR><Up><Tab><Up><Up><End>()<Left>
""inoremap if if ()<left>


" active keypad with windows keyboard
" keypad insert/command mode
map! <ESC>Oo  /
map! <ESC>Oj  *
map! <ESC>Om  -
map! <ESC>Ok  +
map! <ESC>Ol  ,
map! <ESC>OM  ^M
map! <ESC>Ow  7
map! <ESC>Ox  8
map! <ESC>Oy  9
map! <ESC>Ot  4
map! <ESC>Ou  5
map! <ESC>Ov  6
map! <ESC>Oq  1
map! <ESC>Or  2
map! <ESC>Os  3
map! <ESC>Op  0
map! <ESC>On  .

" keypad in normal mode
map <ESC>Oo  /
map <ESC>Oj  *
map <ESC>Om  -
map <ESC>Ok  +
map <ESC>Ol  ,
map <ESC>OM  ^M
map <ESC>Ow  7
map <ESC>Ox  8
map <ESC>Oy  9
map <ESC>Ot  4
map <ESC>Ou  5
map <ESC>Ov  6
map <ESC>Op  1
map <ESC>Or  2
map <ESC>Os  3
map <ESC>Op  0
map <ESC>On  .

