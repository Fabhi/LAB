# LABS
MIT IT Lab Repository

To obtain **partial clone** of this repository, use the following commands:

    $ git init  
    $ git remote add origin -f https://github.com/Fabhi/LAB.git  
    $ git config core.sparseCheckout true #enable this  
    $ cat >> .git/info/sparsecheckout  
    `<folder>`  
    $ git pull origin master  

For example, **to obtain only '4th Sem'**, use the following commands:  

$ git init    
$ git remote add origin -f https://github.com/Fabhi/LAB.git  
$ git config core.sparseCheckout true  
$ cat >> .git/info/sparsecheckout  
`4th Sem`  
$ git pull origin master  
