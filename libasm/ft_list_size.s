section   .text
          global ft_list_size
ft_list_size:
          mov     rax, 0
          mov     r8, rdi
          jmp     loop_start

loop_start:
          cmp     r8, 0   
          je      end_of_list 
          inc     rax
          mov     r8, [r8 + 8]
          jmp     loop_start       


end_of_list:
          ret         
