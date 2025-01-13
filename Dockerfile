FROM debian:stable-slim AS builder
WORKDIR /app
RUN apt-get update && apt-get install -y \
    g++ \
    libcpprest-dev \
    libboost-all-dev \
    libssl-dev \
    cmake
COPY . .
RUN g++ -o moneymoves_sdk main.cpp -lcpprest -lboost_system -lboost_thread -lboost_chrono -lboost_random -lssl -lcrypto

FROM debian:stable-slim AS final
WORKDIR /app
COPY --from=builder /app/moneymoves_sdk /app/moneymoves_sdk
CMD ["./moneymoves_sdk"]