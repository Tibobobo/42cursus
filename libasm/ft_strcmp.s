section   .text
          global ft_strcmp
ft_strcmp:
          mov     rdx, 0                    ; index initialise a 0
          xor     r8, r8                    ; tous les bits du registre a 0
          xor     rcx, rcx                  ; idem
          xor     rax, rax                  ; idem
          jmp     loop_start                ; debut de boucle

loop_start:
          mov     r8b, [rsi + rdx]          ; je copie le byte de str2 dans r8b
          mov     cl, [rdi + rdx]           ; je copie le byte de str1 dans cl
          cmp     r8b, 0                    ; je verifie si on est a la fin d'une des deux
          je      end_of_cmp                ; si oui, on va a la fin
          cmp     r8b, cl                   ; si non, on verifie si les bytes sont identiques
          jne     end_of_cmp                ; si non, on va a la fin
          inc     rdx                       ; si oui, on incremente l'index et on recommence
          jmp     loop_start 

end_of_cmp:
          sub      rcx, r8                  ; je soustrais s1[i] et s2[i] (cette fois ci en prenant les 64 bits du registre)
          mov      rax, rcx                 ; je deplace le resultat dans rax pour pouvoir le retourner
          ret    