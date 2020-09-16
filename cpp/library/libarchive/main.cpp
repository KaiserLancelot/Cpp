// TODO learn libarchive

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <archive.h>
#include <archive_entry.h>

void write_archive(const char* outname, const char** filename) {
  struct archive* a;
  struct archive_entry* entry;
  struct stat st;
  char buff[8192];
  int len;
  int fd;

  a = archive_write_new();
  archive_write_add_filter_zstd(a);
  archive_write_set_format_pax_restricted(a);  // Note 1
  archive_write_open_filename(a, outname);
  while (*filename) {
    stat(*filename, &st);
    entry = archive_entry_new();  // Note 2
    archive_entry_set_pathname(entry, *filename);
    archive_entry_set_size(entry, st.st_size);  // Note 3
    archive_entry_set_filetype(entry, AE_IFREG);
    archive_entry_set_perm(entry, 0644);
    archive_write_header(a, entry);
    fd = open(*filename, O_RDONLY);
    len = read(fd, buff, sizeof(buff));
    while (len > 0) {
      archive_write_data(a, buff, len);
      len = read(fd, buff, sizeof(buff));
    }
    close(fd);
    archive_entry_free(entry);
    filename++;
  }
  archive_write_close(a);  // Note 4
  archive_write_free(a);   // Note 5
}

int main(int argc, const char** argv) {
  (void)argc;
  const char* outname;
  argv++;
  outname = *argv++;
  write_archive(outname, argv);
  return 0;
}
