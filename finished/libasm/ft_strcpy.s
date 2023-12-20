section   .text
          global ft_strcpy
ft_strcpy:
          mov     rax, rdi                  ; on envoie directement l'adresse du pointeur sur dest qui sera notre valeur de retour
          mov     rdx, 0                    ; on initialise a 0 le registre qui va contenir notre index
          jmp     loop_start                ; jump inconditionnel au debut de la boucle de copie

loop_start:
          cmp     byte [rsi + rdx], 0       ; comparaison pour detecter la fin de la string src
          je      end_of_copy               ; si la comparaison est vraie, on jump a la fin de la fonction
          mov     cl, [rsi + rdx]           ; on deplace dans un registre DE 8 BITS le caractere depuis src
          mov     [rdi + rdx], cl           ; on copie ce caractere dans dest au meme index
          inc     rdx                       ; on incremente l'index
          jmp     loop_start                ; on recommence la boucle

end_of_copy:
          mov      byte [rdi + rdx], 0      ; on insere le byte null final a la fin de dest
          ret                               ; on retourne rax qui contient depuis le debut l'adresse de dest