COPY start 1000
. hello this is a comment
FIRST stl RETADR
CLOOP jsub RDREC
lda LENGTH
comp ZERO
jeq ENDFIL
jsub WRREC
j CLOOP
ENDFIL lda EOF
sta BUFFER
lda THREE
sta LENGTH
jsub WRREC
ldl RETADR
end first


