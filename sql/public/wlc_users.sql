create table if not exists wlc_users
(
    id    serial
        primary key,
    name  varchar(64),
    class varchar(32),
    level integer default 1,
    student_id integer
        unique,
    password   varchar(64)
);