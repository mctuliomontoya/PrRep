#lang racket
(define neg
  (lambda (p)
    (if p #f #t)))

(define both
  (lambda (p w)
    (if p w #f)))

(define or
  (lambda (p w)
    (if p #t w)))

(define (factorial n)
  (if (= n 1)
      1
      (* n (factorial (- n 1)))))

(define C1 '(2 4 6 8 10 12 14 17))

(define C2
  (filter
   (lambda (n) (and (even? n) (< n 20) (> n 0)))
    (build-list 20 values)))

(define C3
  (filter
   (lambda (n) (and (> n 15) (< n 30)))
    (build-list 30 values)))