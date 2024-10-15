bits 32

; void bind_GDT(GDT)
; IN:
; [esp + 4] : GDT
global bind_GDT
bind_GDT:
	mov eax, [esp + 4]
	lgdt [eax]
	
	;mov eax, 0x10
	;mov ds, ax
	;mov es, ax
	;mov fs, ax
	;mov gs, ax
	;mov ss, ax
	;jmp 0x08:.return
	;.return:
	ret
