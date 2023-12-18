section     .data
            extern __errno_location
            extern malloc
section   .text
          global ft_list_push_front
ft_list_push_front:
            push    rdi                     ; on save rdi sur la stack pour pouvoir donner a malloc son parametre
            push    rsi                     ; on save aussi rsi pour garder l'adresse de la data (2eme parametre)
            mov     rdi, 16
            call    malloc wrt ..plt        ; malloc 16 bytes(2 pointeurs)
            pop     rsi                     ; on retablit nos deux parametres initiaux
            pop     rdi
            cmp     rax, 0                  ; on verifie son retour
            je      malloc_error            ; si c'est null on jump a malloc_error
            mov     [rax], rsi              ; on met l'adresse de data a l'adresse allouee par malloc
            mov     r8, [rdi]               ; on met dans r8 l'adresse de l'ancien debut de la liste
            mov     [rax + 8], r8           ; on met l'adresse de l'ancien debut de liste dans le next du nouvel element
            mov     [rdi], rax              ; on set le nouveau begin a l'adresse du nouvel element
            ret                             ; on return, peu importe ce qu'il reste dans rax vu que la fonction retourne void

malloc_error:
            call    __errno_location wrt ..plt      ; on recupere dans rax l'adresse de errno
            mov     dword [rax], 12                 ; on met la valeur de errno qui va bien, ENOMEM, pour pouvoir afficher le bon message avec perror
            ret        