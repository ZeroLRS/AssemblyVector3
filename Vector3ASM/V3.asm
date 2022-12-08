.CODE
_Normal PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
movaps xmm1, xmm0
mulps xmm0, xmm0							; vexp2ps apparently only works on zmm registers (AVX-512)
haddps xmm0, xmm2							; horizontally add all the values together, using the empty xmm2 register as a dummy
haddps xmm0, xmm2							; because there are four values, it must be done twice
sqrtps xmm0, xmm0
vbroadcastss xmm0, xmm0						; put the now singular value in xmm0 into each of it's pack slots
divps xmm1, xmm0							; divide the original vector by its magnitude
movdqa XMMWORD PTR [rdx], xmm1

lea rsp, [rbp]
pop rbp
ret
_Normal ENDP

_Normalize PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
movaps xmm1, xmm0
mulps xmm0, xmm0							; vexp2ps apparently only works on zmm registers (AVX-512)
haddps xmm0, xmm2							; horizontally add all the values together, using the empty xmm2 register as a dummy
haddps xmm0, xmm2							; because there are four values, it must be done twice
sqrtps xmm0, xmm0
vbroadcastss xmm0, xmm0						; put the now singular value in xmm0 into each of it's pack slots
divps xmm1, xmm0							; divide the original vector by its magnitude
movdqa XMMWORD PTR [rcx], xmm1

lea rsp, [rbp]
pop rbp
ret
_Normalize ENDP

_Magnitude PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
movaps xmm1, xmm0
mulps xmm0, xmm0							; vexp2ps apparently only works on zmm registers (AVX-512)
haddps xmm0, xmm2							; horizontally add all the values together, using the empty xmm2 register as a dummy
haddps xmm0, xmm2							; because there are four values, it must be done twice
sqrtps xmm0, xmm0
movq rax, xmm0

lea rsp, [rbp]
pop rbp
ret
_Magnitude ENDP

_SqrMagnitude PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
movaps xmm1, xmm0
mulps xmm0, xmm0							; vexp2ps apparently only works on zmm registers (AVX-512)
haddps xmm0, xmm2							; horizontally add all the values together, using the empty xmm2 register as a dummy
haddps xmm0, xmm2							; because there are four values, it must be done twice
movq rax, xmm0

lea rsp, [rbp]
pop rbp
ret
_SqrMagnitude ENDP

_Equals PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax

cmp rcx, rdx
setz al 

lea rsp, [rbp]
pop rbp
ret
_Equals ENDP

_NotEquals PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax

cmp rcx, rdx
setz al
xor al, 1

lea rsp, [rbp]
pop rbp
ret
_NotEquals ENDP
END	