SELECT `etage_salle` AS 'etage', ROUND(AVG(`nbr_siege`)) AS 'sieges'
FROM `db_ylarbi`.`salle`
WHERE 1 GROUP BY `etage_salle`
ORDER BY `etage_salle` ASC;
