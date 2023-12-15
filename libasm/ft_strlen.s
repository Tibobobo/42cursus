section   .text
          global ft_strlen
ft_strlen:
          mov     rax, 0                   ; on met 0 sur rax qui sera la valeur de retour (int i = 0)
          jmp     loop_start               ; on commence la boucle (jmp = unconditional jump)

loop_start:
          cmp     byte [rdi + rax], 0     ; on cherche si on est sur un byte null en additionnant l'adresse du parametre (rdi) avec rax qui contient l'index
          je      end_of_string           ; si le cmp au dessus est vrai, alors on jump a exit (je = jump equal)
          inc     rax                     ; on incremente la valeur sur rax  (i++)
          jmp     loop_start              ; on retourne au debut de la boucle


end_of_string:
          ret                              ; on retourne la valeur sur rax apres le jump (return i)
