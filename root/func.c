double func( double *x, double *p){
	return TMath::Exp(p[0]+x[0]/100);
}
void a(){
	TF1* f = new TF1("func", func, 0., 100., 1);
	f->SetParameter(0, 1);
	TCanvas *c = new TCanvas("a");
	c->Divide(3,2);
	c->cd(1);
	f->Draw();
	TH1F *hist1 = new TH1F("hist1", "hist", 100, 0., 20.);
	for (int i=0; i<1000; i++){
		hist1->Fill(f->GetRandom());
	}
	c->cd(2);
	f->Draw();
//hist1->Draw();
}
