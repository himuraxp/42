SELECT UPPER(compte.nom) AS 'NOM', compte.prenom, abo.prix
FROM `db_ylarbi`.`fiche_personne` AS compte
LEFT JOIN `db_ylarbi`.`membre` AS membre  ON compte.id_perso = membre.id_fiche_perso
LEFT JOIN `db_ylarbi`.`abonnement` AS abo ON membre.id_abo = abo.id_abo
WHERE CAST(abo.prix AS UNSIGNED) > 42
ORDER BY compte.nom ASC, compte.prenom ASC;
