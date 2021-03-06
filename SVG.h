#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black")
{
    cout << "<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";
}

void svg_text(double left, double baseline, string text)
{
  cout<<"<text x='"<<left<<"' y='35'>anything you want</text>"<<endl;
     //if((((i+1)*(max-min)/bin_count)+min)!=max)
       // cout<<fixed<<setprecision(2)<<((i+1)*(max-min)/bin_count)+min<<endl;
}
void show_histogram_svg(const vector<size_t>& bins, double min, double max, size_t bin_count)
{
    svg_begin(400, 300);
    svg_text(20, 20, to_string(bins[0]));
    const size_t screen_width=80;
    const size_t width=screen_width-4;
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    double top = 0;
    string stroke="black";
    string fill="red";
    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > width;

    for (size_t bin : bins)
    {
        if (scaling_needed)
        {
            const double scaling_multiplier = (double)width / max_count;
            bin = (size_t)(bin * scaling_multiplier);
        }

 }
    // for (size_t bin : bins)
        for(size_t i=0; i<bins.size(); i++)
    {
        const double bin_width = BLOCK_WIDTH * bins[i];
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bins[i]));
        if((((i+1)*(max-min)/bin_count)+min)!=max)
        cout<<fixed<<setprecision(2)<<((i+1)*(max-min)/bin_count)+min<<endl;
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,stroke,fill);
        top += BIN_HEIGHT;
    }

    svg_end();
}



#endif // SVG_H_INCLUDED
