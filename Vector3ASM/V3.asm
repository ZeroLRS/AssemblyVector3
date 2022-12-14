.CODE
_Dot PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
movaps xmm1, XMMWORD PTR [rdx]
mulps xmm0, xmm1							; Multiply the values in each vector together
haddps xmm0, xmm2							; horizontally add all the values together, using the empty xmm2 register as a dummy
haddps xmm0, xmm2							; because there are four values, it must be done twice
movq rax, xmm0

lea rsp, [rbp]
pop rbp
ret
_Dot ENDP

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
mulps xmm0, xmm0
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
mulps xmm0, xmm0							; square the vector
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
mulps xmm0, xmm0							; square the vector
haddps xmm0, xmm2							; horizontally add all the values together, using the empty xmm2 register as a dummy
haddps xmm0, xmm2							; because there are four values, it must be done twice

lea rsp, [rbp]
pop rbp
ret
_SqrMagnitude ENDP

; Lots of help from https://geometrian.com/programming/tutorials/cross-product/index.php
_Cross PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
movaps xmm1, XMMWORD PTR [rdx]
movaps xmm2, xmm0
movaps xmm3, xmm1

shufps xmm2, xmm2, 201						; 201 = _MM_SHUFFLE(3, 0, 2, 1);
shufps xmm3, xmm3, 210						; 210 = _MM_SHUFFLE(3, 1, 0, 2);

movaps xmm4, xmm2

mulps xmm2, xmm1
mulps xmm4, xmm3

shufps xmm2, xmm2, 201						; 201 = _MM_SHUFFLE(3, 0, 2, 1);

subps xmm4, xmm2

movdqa XMMWORD PTR [r8], xmm4

lea rsp, [rbp]
pop rbp
ret
_Cross ENDP

_Add PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
movaps xmm1, XMMWORD PTR [rdx]
addps xmm0, xmm1

movdqa XMMWORD PTR [r8], xmm0

lea rsp, [rbp]
pop rbp
ret
_Add ENDP

_Distance PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
movaps xmm1, XMMWORD PTR [rdx]

subps xmm1, xmm0
mulps xmm1, xmm1							; square all of the values
haddps xmm1, xmm2							; horizontally add all the values together, using the empty xmm2 register as a dummy
haddps xmm1, xmm2							; because there are four values, it must be done twice
sqrtps xmm1, xmm1
movaps xmm0, xmm1

lea rsp, [rbp]
pop rbp
ret
_Distance ENDP

_SqrDistance PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
movaps xmm1, XMMWORD PTR [rdx]

subps xmm1, xmm0
mulps xmm1, xmm1							; square all of the values
haddps xmm1, xmm2							; horizontally add all the values together, using the empty xmm2 register as a dummy
haddps xmm1, xmm2							; because there are four values, it must be done twice
movaps xmm0, xmm1

lea rsp, [rbp]
pop rbp
ret
_SqrDistance ENDP

_Subtract PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
movaps xmm1, XMMWORD PTR [rdx]
subps xmm0, xmm1

movdqa XMMWORD PTR [r8], xmm0

lea rsp, [rbp]
pop rbp
ret
_Subtract ENDP

_MultiplyScalar PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
movaps xmm0, XMMWORD PTR [rcx]
vbroadcastss xmm1, xmm1						; put the scalar value into all slots of xmm1
mulps xmm0, xmm1

movdqa XMMWORD PTR [r8], xmm0

lea rsp, [rbp]
pop rbp
ret
_MultiplyScalar ENDP

_Equals PROC
push rbp
sub rsp, 20h
lea rbp, [rsp + 20h]

xor rax, rax
cmp rcx, rdx
setz al										; set the return value to the result of the compare

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
setz al										; set the return value to the result of the compare
xor al, 1									; invert the result

lea rsp, [rbp]
pop rbp
ret
_NotEquals ENDP
END	