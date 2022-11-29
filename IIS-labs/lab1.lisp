((lambda (x r g h) (
  cond
    ((> x g) (+(+ r x)(* x x)))
	((AND (>= x g)(< x h)) (- r (* x x x)))
    (t (/(- 1 r)(* x x)))
)) 2 3 1 5) 

(defun y(x r g h) (
  cond
    ((> x g) (+(+ r x)(* x x)))
	((AND (>= x g)(< x h)) (- r (* x x x)))
    (t (/(- 1 r)(* x x)))
))
