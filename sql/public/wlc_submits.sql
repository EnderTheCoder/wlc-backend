create table if not exists wlc_submits
(
    id          serial
        primary key,
    type        varchar(16),
    user_id     integer,
    create_time bigint,
    content     text,
    task_id     integer
);