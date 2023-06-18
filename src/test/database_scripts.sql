create table id_to_password
(
    client_id int references clients (client_id),
    client_password_hash text
)


create table clients
(
    client_id    SERIAL primary key,
    client_login   varchar(100),
    client_games   int not null,
    client_wins    int not null,
    client_balance int not null
)
