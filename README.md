# Tema2_PA
Graph Data Structure And Algorithms

						Tema 2 Proiectarea Aldoritmilor
						 "ROBIN HOOD AND GRAPHS"
Timp de rezolvare 4 zile.

Problema intampinate: Solutia optima din punct de vedere a timpului a fost 
					  gasita dupa cateva incercari care erau putin mai 
					  costisitoare decat timpul alocat.

Problema 1: "Save robin hood"
	Problema a fost rezolvata eficient cu o logica aproximativ ca la cautarea
	binara doar ca aici caut secventa cea mai mica de noduri care trebuie 
	blocate pentru ca robin hood sa nu fie prins de lorzi, de aici am pornit 
	cu ideea ca daca impart vectorul de permutari in sumatate si blochez 
	totate nodurile pe care le am in dreapta si fac un dfs pe nodurile ramase
	astfel incat sa verific daca exista drum de la nodul 1(unde se afla robin 
	hood) pana la oricare nod ocupat de lorzi, daca raspunsul este afirmativ 
	atunci trebuie sa blochez mai multe noduri, in caz contrar verific daca 
	blochez mai putine noduri voi avea tot raspunsul afirmativ.
	K = numarul de permutari;
	N = Noduri;
	M = Muchii;
======================== Complexitate: O(log K * (|M| + |N|)) ================

Problema 2: "Robin Hood stealing for the poor"
	Dupa cum se specifica si in enunt, "Daca Robin porneste din orasul A, 
	acesta nu va mai putea ajunge niciodata înapoi în orasul A, oricare ar 
	fi acel oras A", deci Graful pe care il formam va fi aciclic.Problema poate
	fi rezolvata cu Bellman Ford dar este prea costisitoare din punct de vedere
	a timpului, de aceea am inceput sa caut o optimizare a acestui algoritm 
	dupa care am gasit un articol in care era specificata optimizarea facuta cu
	sortarea topologica. Algoritmul a fost realizat in felul urmator: Am sortat 
	tot graful cu Sortarea Topologica pastrand ordinea nodurilor intr-un vector,
	dupa  care am folosit Bellman ford pentru a gasi costul minim pentru fiecare
	drum. Drumul minim de la sursa la destinatie se afla pe pozitia destinatiei 
	din vectorul de costuri.

	M = Muchii;
	N = Noduri;
========================== Complexitate: O(|M| + |N|) =========================

Problema 3: "Fooling the guards"
	Pentru aceasta problema am folosit Dijkstra deoarece stim ca nu are costuri 
	negative graful am ataptat algoritmul pentru a rezolva problema astfel, 
	calculam ca dupa ce va trece printr-un nodul sa ramana cu cat mai multa 
	energie(Energia a fost calculata dupa formula data in enunt). Apoi pentru 
	memorarea drumului parcurs de la sursa la destinatie am memorat intr-un 
	vector parintii nodurilor astfel incat stiind nodul destinatie sa pot sa 
	ajung la nodul sursa(Care nu mai are parinti). Aldoritmul a fost realizat 
	dupa pseodocodul din breviarul de laborator 9, folosind coada de prioritati.

	M = Muchii;
	N = Noduri;
========================== Complexitate: O(|M| * log|N|) ======================
