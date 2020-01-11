set background=dark
set cursorline
set nu

set showmatch
set smartcase

set smartindent
set backspace=indent,eol,start
set expandtab
set tabstop=4
set softtabstop=4
set shiftwidth=4

" show status bar
set laststatus=2

set incsearch
set hlsearch
" ignore case search
set ignorecase

set wrap
" don't wrap inside word
set linebreak

set completeopt=preview,menu

set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8

" folding
set fdm=syntax

filetype on
syntax on
" colorscheme darkblue
set title
" set path=.,**
" set tags= xxxxxx
" set autochdir

syntax on

" Highlight trailing spaces
" http://vim.wikia.com/wiki/Highlight_unwanted_spaces
highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$/
autocmd BufWinEnter * match ExtraWhitespace /\s\+$/
autocmd InsertEnter * match ExtraWhitespace /\s\+\%#\@<!$/
autocmd InsertLeave * match ExtraWhitespace /\s\+$/
autocmd BufWinLeave * call clearmatches()

" replace Tab with '>-', and Trailing spaces with '-'
set list
set listchars=tab:»·

" persistent undo
set undofile
set undodir=$HOME/.vim/undo
set undolevels=1000
set undoreload=1000

if has("termguicolors")
    " fix bug for vim
    let &t_8f = "\<Esc>[38;2;%lu;%lu;%lum"
    let &t_8b = "\<Esc>[48;2;%lu;%lu;%lum"

    " enable true color
    set termguicolors
endif
