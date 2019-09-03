#include <common.h>

#define USAGE "Usage: %s [-d] [-t times] [-s step] [-h] sft\n"
#define DEVNULL "/dev/null"

int main(int argc, char **argv)
{
  uint8_t sft;
  int32_t lpih;
  int32_t cos;
  int32_t i;
  int32_t step = 16;
  FILE *gp;
  int opt;
  FILE *fp;
  uint8_t times = 2;
  fp = fopen(DEVNULL, "w");
  if (!fp) {
    perror(DEVNULL);
    exit(1);
  }
  while (-1 != (opt = getopt(argc, argv, "dt:s:h"))) {
    switch (opt) {
      case 'd':
        fclose(fp);
        fp = stdout;
        break;
      case 't':
        times = atoi(optarg);
        times = (0 == times) ? 1 : times;
        break;
      case 's':
        step = atoi(optarg);
        step = (0 == step) ? 1 : step;
        break;
      case 'h':
      case '?':
      default:
        fprintf(stderr, USAGE, argv[0]);
        exit(1);
    }
  }
  if (argc != optind + 1) {
    fprintf(stderr, USAGE, argv[0]);
    exit(1);
  }
  sft = SFT_LIMIT(atoi(argv[optind]));
  lpih = float_to_fr32_pih(sft);
  step = lpih / step;
  fprintf(fp, "lpih: %.10f [%08X]\n", fr32_to_float(lpih, sft), lpih);
  fprintf(fp, "step: %.10f [%08X]\n", fr32_to_float(step, sft), step);
  if (0 == step)
    exit(1);
  gp = popen("gnuplot -persist", "w");
  fprintf(gp, "set style line 1 pt 3\nplot '-' linestyle 1 title \"cos(x)\"\n");
  for (i = -lpih * times; i <= lpih * times; i+=step) {
    cos = cos_fr32(i, sft);
    fprintf(gp, "%.10f\t%.10f\n", fr32_to_float(i, sft), fr32_to_float(cos, sft));
    fprintf(fp, "(%+f, %+f) ", fr32_to_float(i, sft), fr32_to_float(cos, sft));
    fprintf(fp, "[%08X, %08X]\n", i, cos);
  }
  pclose(gp);
  return 0;
}
