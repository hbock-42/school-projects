Creation d'une fonction qui renvoit une ligne terminée par un retour à la ligne lue depuis un descripteur de fichier.

Cette fonction est destinée à être utilisée dans d'autres projets.

Exemple de main pour tester cette fonction:

	int main()
	{
	    char *line;

	    while (get_next_line(0, &line) > 0)
	    {
	        write(1, line, strlen(line));
	    }
	    return (0);
	}

Lecture sur stdin car le fd est 0.