# simple-encrypter 
simple ASCII cesar cypher file encripter written in c.  

## Usage
- compile with `make`
- `./simple-enc -d|-e key [numFiles] `  
    where key should be a number between 1 and 255  
    if `numFiles` is not specified the stdin string will be crypted and redirected to stdout

## Features
- Encrypt and decrypt files from command line 
