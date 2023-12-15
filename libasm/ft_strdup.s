section     .data
            extern __errno_location
            extern malloc
            extern ft_strlen
            extern ft_strcpy
section     .text
            global ft_strdup
ft_strdup:
            call    ft_strlen                       ; on appelle strlen sur la string dans rdi
            inc     rax                             ; on l'incremente pour le null byte final
            push    rdi                             ; on save le pointeur sur la str originale sur la stack
            mov     rdi, rax                        ; on bouge la len + 1 sur rdi pour l'envoyer a malloc
            call    malloc wrt ..plt                ; on appelle malloc
            cmp     rax, 0                          ; on verifie son retour
            je      malloc_error                    ; si c'est null on jump a malloc_error
            pop     rsi                             ; sinon, on recupere la str originale pour la mettre en 2eme parametre de strcpy
            mov     rdi, rax                        ; on met le pointeur donne par malloc en premier param
            call    ft_strcpy                       ; on appelle strcpy avec les deux parametres necessaires
            ret                                     ; on retourne rax qui contient l'adresse de la chaine copiee

malloc_error:
            call    __errno_location wrt ..plt      ; on recupere dans rax l'adresse de errno
            mov     dword [rax], 12                 ; on met la valeur de errno qui va bien, ENOMEM, pour pouvoir afficher le bon message avec perror
            mov     rax, 0                          ; on return null
            pop     rsi                             ; on pop ce qu'on avait push avant pour rendre la stack dans son etat initial
            ret
