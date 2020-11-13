typedef struct ListNodeInt {
    int val;
    struct ListNodeInt *next;
} ListNodeInt;

typedef struct FifoInt {
  ListNodeInt *first;
  ListNodeInt *last;
} FifoInt;

FifoInt fifo_int_new() {
  struct FifoInt queue = {
    .first = NULL,
    .last = NULL,
  };
  return queue;
}

void fifo_int_push(FifoInt *fifo, int val) {
  struct ListNodeInt node = {
    .val = val,
    .next = NULL
  };
  ListNodeInt *nodeptr = CARP_MALLOC(sizeof(FifoInt));
  assert(nodeptr);
  *nodeptr = node;
  if (!fifo->first) {
    fifo->first = nodeptr;
    fifo->last = nodeptr;
  } else {
    fifo->last->next = nodeptr;
    fifo->last = nodeptr;
  }
}

int fifo_int_pop(FifoInt *fifo) {
  int value = fifo->first->val;
  ListNodeInt *next = fifo->first->next;
  CARP_FREE(fifo->first);
  fifo->first = next;
  if (!next) {
    fifo->last = NULL;
  }
  return value;
}

bool fifo_int_is_empty(FifoInt *fifo) {
  return !fifo->first;
}

void fifo_int_delete_node(ListNodeInt *node) {
  if (node) {
    ListNodeInt *next = node->next;
    CARP_FREE(node);
    if (next) {
      fifo_int_delete_node(next);
    }
  }
}

void fifo_int_delete(FifoInt fifo) {
  fifo_int_delete_node(fifo.first);
}

typedef struct ListNodeSocket {
    Socket val;
    struct ListNodeSocket *next;
} ListNodeSocket;

typedef struct FifoSocket {
  ListNodeSocket *first;
  ListNodeSocket *last;
} FifoSocket;

FifoSocket fifo_socket_new() {
  struct FifoSocket socket = {
    .first = NULL,
    .last = NULL,
  };
  return socket;
}

void fifo_socket_push(FifoSocket *fifo, Socket socket) {
  struct ListNodeSocket node = {
    .val = socket,
    .next = NULL
  };
  ListNodeSocket *nodeptr = CARP_MALLOC(sizeof(FifoSocket));
  assert(nodeptr);
  *nodeptr = node;
  if (!fifo->first) {
    fifo->first = nodeptr;
    fifo->last = nodeptr;
  } else {
    fifo->last->next = nodeptr;
    fifo->last = nodeptr;
  }
}

Socket fifo_socket_pop(FifoSocket *fifo) {
  Socket value = fifo->first->val;
  ListNodeSocket *next = fifo->first->next;
  CARP_FREE(fifo->first);
  fifo->first = next;
  if (!next) {
    fifo->last = NULL;
  }
  return value;
}

bool fifo_socket_is_empty(FifoSocket *fifo) {
  return !fifo->first;
}

void fifo_socket_delete_node(ListNodeSocket *node) {
  if (node) {
    ListNodeSocket *next = node->next;
    CARP_FREE(node);
    if (next) {
      fifo_socket_delete_node(next);
    }
  }
}

void fifo_socket_delete(FifoSocket fifo) {
  fifo_socket_delete_node(fifo.first);
}
