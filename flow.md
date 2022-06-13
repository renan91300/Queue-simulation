## Variáveis: Valores iniciais
 * service_period (Período de atendimento): 480 min (8 horas)
 * service_time_performed (Tempo de atendimento realizado): 0 min
 * min_service_time (Tempo mínimo de atendimento): 1 min
 * max_service_time (Tempo máximo de atendimento): 4 min
 * arrival_time (Hora de chegada): 0 min
 * min_arrival_time (Tempo mínimo de chegada): 0 min
 * max_arrival_time (Tempo máximo de chegada): 3 min
 * waiting_time (Tempo de espera): 0 min

## Fluxo:

  Enquanto a hora de chegada (arrival_time) for menor que o Período de serviço  (service_period):

    1. Gerar tempo de chegada de um cliente
    2. incrementar o arrival_time com o tempo gerado
    3. Inserir um novo elemento na fila (novo cliente) com a hora que ele chegou (arrival_time)

  Enquanto a fila não for vazia:

    1. Gerar um tempo de atendimento para o cliente    
    2. Se o service_time_performed for maior que o arrival_time do cliente:
      - Incrementar o waiting_time com o a diferença do service_time_performed e do o arrival_time do cliente
    3. Incrementar o service_time_performed com o tempo de atendimento gerado
    4. Remover cliente da fila


Implementação para vários caixas e várias filas:

  Variáveis:
   * amount_cashiers
   * amount_queues

  2 ou mais filas:
    
    1. Gerar tempo de espera de um cliente;
    2. Enfileirar ele na fila com maior probabilidade.
       - A probabilidade é calculada multiplicando a quantidade

  