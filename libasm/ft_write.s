section   .data
            extern __errno_location             ; on va avoir besoin de recuperer l'adresse de errno pour ce thread
section   .text
          global ft_write
ft_write:
            mov     rax, 1                      ; 1 = numero de l'appel system write
            syscall                             ; appel systeme (avec comme arguments les 3 deja contenus dans rdi, rsi et rdx, pratique !)
            cmp     rax, 0                      ; on compare la valeur de retour de l'appel systeme avec 0
            jl      syscall_error               ; si c'est inferieur (jl = jump lower) on va vers la fonction syscall_error
            ret                                 ; sinon on retourne rax qui contient bien la valeur de retour de l'appel systeme

syscall_error:
            neg     rax                         ; on recupere la valeur absolue du retour de l'appel systeme
            mov     rcx, rax                    ; on la stock dans un registre libre parce que l'appel suivant va ecraser rax
            call    __errno_location wrt ..plt  ; on appelle __errno_location qui renvoie l'adresse de errno pour ce thread
            mov     [rax], rcx                  ; on met a cette addresse memoire la valeur que nous a donne l'appel systeme
            mov     rax, -1                     ; on retourne -1 pour indiquer qu'une erreur a eu lieu
            ret