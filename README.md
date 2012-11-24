MI-PAR-sequnece-Game-of-Live
=============================

university: Sequential solution of the reverse game of life

Úloha RZI: Reverzní hra Život
Vstupní data:

n,m = přirozená čísla reprezentující velikost hrací plochy
S = požadovaná koncová konfigurace
q = počet zpětných tahů
a = přirozené číslo reprezentující možnou chybu cílové konfigurace, 5 < a < 10
Úkol:

Uvažujte hru Život (bere se v úvahu 8-okolí) na hrací ploše n*m. Stav hrací plochy lze zakódovat jako binární vektor délky n*m (průchod hrací plochou po řádcích), kde 0 reprezentuje mrtvou buňku, 1 reprezentuje živou buňku. Buňky mimo hrací plochu jsou pokládány za mrtvé. Nalezněte takovou konfiguraci K, aby po provedení q iterací hry Život platilo pro výslednou konfigurace T: ham(T,S) < = a, kde ham(X,Y) reprezentuje Hammingovu vzdálenost dvou binárních vektorů X a Y. Řešení může být více, najděte to, které má maximální Hammingovu váhu (obsahuje v sobě maximální počet jedniček).
Výstup algoritmu:

Výpis konfigurace K a jeho Hammingovu váhu, dále všech q iterací hry Život a Hammingovu vzdálenost mezi T a S.
Sekvenční algoritmus:

Sekvenční algoritmus je typu BB-DFS s omezenou hloubkou stromu stavů na n*m. Řešení nemusí existovat.
Cena, kterou maximalizujeme, je Hammingovu váhu K. Algoritmus končí, když je cena rovna dolní mezi nebo když prohledá celý stavový prostor.

Triviální dolní mez je 0.

Triviální horní mez je m * n.
Paralelní algoritmus:

Paralelní algoritmus je typu L-PBB-DFS-D. 