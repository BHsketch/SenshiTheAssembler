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
THREE WORD 3
ZERO WORD 0
RETADR RESW 1
LENGTH RESW 1
end first


