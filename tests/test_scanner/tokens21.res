293  void
280  Example
287  (
273  )
283  labels
280  lab1
275  ,
280  lab2
289  ;
292  vars
280  x
275  ,
280  y
274  :
280  integer
289  ;
278  functions
293  void
280  f
287  (
280  a
275  ,
280  b
274  :
280  integer
273  )
285  {
281  if
287  (
280  a
261  <=
280  b
273  )
285  {
279  goto
280  lab1
289  ;
271  }
276  else
285  {
279  goto
280  lab2
289  ;
271  }
271  }
285  {
280  x
297  =
282  10
289  ;
280  y
297  =
282  20
289  ;
280  lab1
274  :
280  write
287  (
280  x
273  )
289  ;
280  lab2
274  :
280  write
287  (
280  y
273  )
289  ;
280  write
287  (
280  x
275  ,
280  y
273  )
289  ;
271  }
20 lines read
