# kubernetes-intro
1. Разобраны причины восстановления pods после удаления, описано в PR.
2. Создан Dockerfile и помещен в директорию kubernetes-intro/web
3. Создан манифест для web-pod и помещен в директорию kubernetes-intro
4. Создан исправленный манифест для frontend-pod и помещен в директорию kubernetes-intro
# kubernetes-controllers
1. Разобраны понятия Replicaset и Deployment, созданы манифесты
2. Реализованы сценарии развертывания blue-green и Reverse Rolling Update
3. Разобраны понятия Probes и Daemonset, пробы добавлены в манифесты
4. Создан DaemonSet для NodeExporter, и применен также на master ноду
# kubernetes-networks
1. Создан Deployment с Liveness и Readyness пробами и стратегией развертывания
2. Созданы Service с ClusterIP и LoadBalancer
3. Разобран балансировщик MetalLB, созданы соответствующие манифесты
4. Сделан сервис LoadBalancer, открывающий доступ к CoreDNS
5. Изучены Ingress-контроллеры, создан http-балансировщик для подов Web
6. Создан https Ingress для kubernetes-Dasboard
7. Создан Ingress для Canary подов, отправляющий 10% траффика в неймспейс Canary
# kubernetes-security
1. Создан ServiceAccount bob и привязан к класстерной роле admin. Создан ServiceAccount dave и ни к какой роле не привязан, он ничего и не сможет.
2. Создан ServiceAccount carol в NS prometheus, создана кластерная роль pods-viewer. Сущности связаны с помощью ClusterRoleBinding.
3. Созданы ServiceAccounts jane и ken, созданы RoleBinding для них к ролям admin и view в NS dev.
# kubernetes-volumes
1. Применены готовые манифесты StatefulSet и HeadlessService для minio.
2. Хранение переменных окружения переделано на Kubernetes Secrets.
# kubernetes-templating
1. Создан kubernetes cluster в yandex cloud
2. Установлен ingress-nginx
3. Установлен и настроен cert-manager через helm
4. Установлен и настроен chartmuseum через helm
5. Установлен и настроен habror через helm
6. Написан helmfile для установке группы чартов
7. На примере hipster-shop разобрано создание чартов, подтягивание локальных зависимостей и зависимостей из репозиториев. Написание Values.yaml
8. Написан чарт для paymentservice и shippingservice с помощью kubecfg
9. Созданы kustomize шаблоны для emailservice