FROM nginx:latest
ARG UID=1001
COPY files.conf /etc/nginx/conf.d/default.conf
COPY files/. /app
EXPOSE 8000