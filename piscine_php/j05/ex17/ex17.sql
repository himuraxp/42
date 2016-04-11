SELECT count(*) AS nb_abo, ROUND(AVG(prix) - 1, 0) AS moy_abo, SUM(duree_abo) % 42 AS ft FROM abonnement;
