#include <linux/module.h> // Necessário para todos os modulos utilizados
#include <linux/moduleparam.h> // Necessário para o macro module_param
#include <linux/kernel.h> // Necessário para os macros KERN_...
#include <linux/init.h> // Necessário para os macros __init e __exit
MODULE_LICENSE("EQUIPE: EDUARDO ALMEIDA DE QUEIROZ, JUAN FELIPE SERAFIM DOS SANTOS, VICTOR EMAUEL PESSOA DA SILVA");


static char *parametro = "texto padrao";
module_param(parametro, charp, 0); //esse é o macro para passagem de parâmetros ao módulo em questão. Caso não seja passado nenhum parâmetro ao adicionar o módulo ao kernel, o valor padrão será utilizado.
//exemplo de passagem de parâmetro-> sudo insmod nomeDoModulo.ko nomeVariavel=alguma coisa dependendo do seu tipo (caso inteiro, um numero; caso char, um caractere; caso string, uma cadeia de caracteres dentro das aspas)

static int __init inicializacaoDoModulo(void)
{
	printk(KERN_INFO "===========\nINICIALIZACAO DO MODULO!!!\n===========\n");
	return 0;
}

static void __exit conclusaoDoModulo(void)
{
	printk(KERN_INFO "===========\nCONCLUSAO DO MODULO COM O VALOR DE PARAMETRO=%s\n===========\n",parametro);
}

module_init(inicializacaoDoModulo);
module_exit(conclusaoDoModulo);