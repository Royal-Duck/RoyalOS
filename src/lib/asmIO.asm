bits 32

; void asm_IO_port_out(uint16_t port, char byte)
; IN:
; [esp + 4] : port
; [esp + 6] : byte
global asm_IO_port_out
asm_IO_port_out:
	mov dx, [esp + 4]
  mov al, [esp + 8]
  out dx, al
	ret

; void asm_IO_port_out(uint16_t port, char byte)
; IN:
; [esp + 4] : port
;	[esp + 6] : return_adress
global asm_IO_port_in
asm_IO_port_in:
	mov dx, [esp + 4]
	in al, dx
	mov [esp + 6], al
