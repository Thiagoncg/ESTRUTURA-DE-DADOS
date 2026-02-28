#include <stdio.h>
#include <time.h> // Necessário para pegar a data atual do sistema automaticamente

int main() {
    // Declaração das variáveis básicas
    char nome[50];
    char rg[20];
    int dia_nasc, mes_nasc, ano_nasc;
    float nota;

    // --- 1. Entrada de Dados (O Formulário) ---
    printf("--- FORMULARIO DO ALUNO ---\n");
    
    printf("Nome completo: ");
    // Lê até 49 caracteres ou até o usuário apertar Enter (permite espaços)
    scanf(" %49[^\n]", nome); 
    
    printf("RG: ");
    scanf("%s", rg); // Lê o RG (sem espaços)
    
    printf("Data de nascimento (formato: Dia Mes Ano, ex: 15 08 2005): ");
    scanf("%d %d %d", &dia_nasc, &mes_nasc, &ano_nasc);
    
    printf("Nota do aluno: ");
    scanf("%f", &nota);

    // --- 2. Processamento (Cálculo da Idade) ---
    // Estrutura básica do C para pegar a data de hoje
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int ano_atual = tm.tm_year + 1900;
    int mes_atual = tm.tm_mon + 1;
    int dia_atual = tm.tm_mday;

    // Calcula a diferença de anos
    int idade = ano_atual - ano_nasc;

    // Se o mês atual for menor que o mês de nascimento, 
    // ou se for o mesmo mês mas o dia de hoje for menor que o dia do aniversário,
    // significa que ele ainda não fez aniversário neste ano, então subtraímos 1.
    if (mes_atual < mes_nasc || (mes_atual == mes_nasc && dia_atual < dia_nasc)) {
        idade--;
    }

    // --- 3. Saída de Dados (Apresentação dos Resultados) ---
    printf("\n--- RESULTADO FINAL ---\n");
    printf("Aluno(a): %s\n", nome);
    printf("RG: %s\n", rg);
    printf("Idade: %d anos\n", idade);
    printf("Nota: %.2f\n", nota); // %.2f mostra a nota com duas casas decimais

    // Lógica para Aprovação ou Reprovação
    if (nota >= 7.0) {
        printf("Status: APROVADO!\n");
    } else {
        printf("Status: REPROVADO.\n");
    }
    printf("-----------------------\n");

    return 0;
}