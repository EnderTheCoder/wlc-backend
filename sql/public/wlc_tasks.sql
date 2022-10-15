create table if not exists wlc_tasks
(
    id          serial
        primary key,
    class       integer,
    students    text,
    details     text,
    create_time bigint,
    limit_time  bigint
);