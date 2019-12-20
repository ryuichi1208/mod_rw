void * te_chk_and_malloc (void *ptr, long *current_bound,
		const long needed, const size_t size)
{
    if (*current_bound < 0)
	return (NULL);
    if (needed <= *current_bound)
	return (ptr);
    if (*current_bound > 0)
	Free (ptr);
    *current_bound += needed;
    return ((void *) malloc (*current_bound * size));
}

void * te_chk_and_realloc (void *ptr, long *current_bound,
		 const long needed, const int size)
{
    if (*current_bound < 0)
	return (NULL);
    if (needed <= *current_bound)
	return (ptr);
    if (*current_bound == 0) {
	*current_bound += needed;
	return ((void *) malloc (*current_bound * size));
    }
    *current_bound += needed;
    return ((void *) realloc (ptr, *current_bound * size));
}
