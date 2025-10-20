#lang racket
 
(require parser-tools/yacc  "Lexer.rkt")
 
(define myparser
  (parser
    (start input)
    (end EOF)

    (tokens value-tokens op-tokens )

    (src-pos)

    (error (lambda (a b c d e) (begin (printf "a = ~a\nb = ~a\nc = ~a\nd = ~a\ne = ~a\n" a b c d e) (void))))   

    ;;(precs    
    ;;  (left ADD SUBTRACT)
    ;;  (left PRODUCT DIVISION)
    ;;  (nonassoc NEG)
    ;;  (left POWER))

    (grammar
      (input [() '()]
             [(input line) (append $1 $2)])

      (line [(NEWLINE) '()]
            [(exp NEWLINE) (list $1)])

      (exp [(exp ADD term)      (list $1 'ADD $3)]
           [(exp SUBTRACT term) (list $1 'SUBTRACT $3)]
           [(term)              $1])
           ;;[(exp PRODUCT exp )  (* $1 $3)]
           ;;[(exp DIVISION exp ) (/ $1 $3)]
           ;;[(exp POWER exp )    (expt $1 $3)]
           ;;[(LPARAM exp RPARAM) $2]   

      (term [(term PRODUCT factor)  (list $1 'PRODUCT $3)]
            [(term DIVISION factor) (list $1 'DIVISION $3)]
            [(term POWER factor)    (list $1 'POWER $3)]
            [(factor)               $1])

      (factor [(NUMBER)            (list 'NUMBER $1)]
              [(ID)                (list 'ID $1)]
              [(LPARAM exp RPARAM) $2])
    )
  )
)
             
(define (parse ip)
  (port-count-lines! ip)  
  (myparser (lambda () (next-token ip))))

(provide parse)
