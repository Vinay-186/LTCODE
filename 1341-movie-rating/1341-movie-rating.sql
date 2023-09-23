(
  SELECT u.name as results
  FROM users u
  INNER JOIN movierating USING (user_id)
  GROUP BY user_id
  ORDER BY count(*) desc, u.name
  LIMIT 1
)
UNION ALL
(
  SELECT m.title as results
  FROM movies m
  INNER JOIN movierating mr USING (movie_id)
  WHERE SUBSTRING(created_at, 1, 7) = '2020-02'
  GROUP BY movie_id
  ORDER BY AVG(rating) desc, m.title 
  LIMIT 1
);