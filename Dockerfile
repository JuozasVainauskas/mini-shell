FROM gcc:12.2.0-bullseye as builder
WORKDIR /app
COPY ./include ./include
COPY ./src ./src
COPY ./Makefile ./Makefile
RUN make build

FROM debian:11.6
RUN adduser user
USER user
WORKDIR /app
COPY --from=builder /app/build/app /app
CMD ["./app"]
