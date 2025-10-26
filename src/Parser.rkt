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
             [(input statement_list) (append $1 $2)])

      (statement_list [(statement_list statement) (append $1 $2)]
                      [(statement) $1])
      (statement [(exp_statement) $1])

      (exp_statement [(END_STATEMENT) '()]
                     [(exp END_STATEMENT) $1])

      (exp [(exp ADD term)      (list $1 'ADD $3)]
           [(exp SUBTRACT term) (list $1 'SUBTRACT $3)]
           [(term)              $1])

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
