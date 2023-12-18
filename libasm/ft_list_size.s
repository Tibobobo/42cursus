section   .text
          global ft_list_size
ft_list_size:
          mov     rax, 0            ; index initialise
          mov     r8, rdi           ; on travaille sur une copie pour pas modif le parametre donne
          jmp     loop_start        ; on commence a compter

loop_start:
          cmp     r8, 0             ; pointeur NULL ?
          je      end_of_list       ; si oui, on return rax
          inc     rax               ; si non, on incremente
          mov     r8, [r8 + 8]      ; on va sur next (void * = 8 bytes)
          jmp     loop_start        ; on recommence la boucle


end_of_list:
          ret         
