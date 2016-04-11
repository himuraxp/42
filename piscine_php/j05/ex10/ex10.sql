SELECT `titre` AS 'Titre', `resum` AS 'Resume', `annee_prod`
FROM `db_ylarbi`.`film` AS film
INNER JOIN `db_ylarbi`.`genre` AS genre ON genre.`id_genre` = film.`id_genre`
WHERE genre.`nom` = 'erotic';
